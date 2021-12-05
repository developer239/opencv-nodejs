import { Vec2 } from '../../../index'

describe('[core] Vec2', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const point = new Vec2(1, 2)

      expect(point.x).toStrictEqual(1)
      expect(point.y).toStrictEqual(2)
    })
  })
})
