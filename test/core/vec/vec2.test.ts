import { Vec2 } from '../../../index'

describe('[core] Vec2', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const point = new Vec2(4, 3)

      expect(point.x).toStrictEqual(4)
      expect(point.y).toStrictEqual(3)
    })
  })
})
