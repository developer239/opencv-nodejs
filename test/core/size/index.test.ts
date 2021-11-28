import { Rect } from '../../../index'

describe('[core] Rect', () => {
  describe('constructor', () => {
    it('initializes from empty constructor', () => {
      const rect = new Rect()

      expect(rect.x).toStrictEqual(0)
      expect(rect.y).toStrictEqual(0)
      expect(rect.width).toStrictEqual(0)
      expect(rect.height).toStrictEqual(0)
    })

    it('initializes from numbers', () => {
      const rect = new Rect(10, 20, 30, 40)

      expect(rect.x).toStrictEqual(10)
      expect(rect.y).toStrictEqual(20)
      expect(rect.width).toStrictEqual(30)
      expect(rect.height).toStrictEqual(40)
    })
  })
})
